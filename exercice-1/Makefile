.POSIX:
CC      = cc
CFLAGS  = -std=c11 -Wall -Wextra -O3 -mcx16 -pthread #-DDEBUG
LDFLAGS = -pthread
#LDLIBS  = -latomic

C= $(wildcard *.c)
H= $(wildcard *.h)
POSIX_SRCS := $(filter-out %Atomic.c %TestAndSet.c, $(C))
ATOMIC_SRCS := $(filter-out %POSIX.c %TestAndSet.c, $(C))
TESTANDSET_SRCS := $(filter-out %POSIX.c %Atomic.c, $(C))
DEPS= $(H:.h)
POSIX_OBJS= $(POSIX_SRCS:.c=.o)
ATOMIC_OBJS= $(ATOMIC_SRCS:.c=.o)
TESTANDSET_OBJS= $(TESTANDSET_SRCS:.c=.o)

posix: $(POSIX_OBJS) $(DEPS)
	$(CC) $(LDFLAGS) -o mySoftwarePosix $(POSIX_OBJS) $(LDLIBS)

atomic: $(ATOMIC_OBJS) $(DEPS)
	$(CC) $(LDFLAGS) -o mySoftwareAtomic $(ATOMIC_OBJS) $(LDLIBS)

testandset: $(TESTANDSET_OBJS) $(DEPS)
	$(CC) $(LDFLAGS) -o mySoftwareTestAndSet $(TESTANDSET_OBJS) $(LDLIBS)

clean:
	rm -f mySoftwarePosix mySoftwareAtomic mySoftwareTestAndSet $(POSIX_OBJS) $(ATOMIC_OBJS) $(TESTANDSET_OBJS)

runposix: clean posix
	./mySoftwarePosix

runatomic: clean atomic
	./mySoftwareAtomic

runtestandset: clean testandset
	./mySoftwareTestAndSet