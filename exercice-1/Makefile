.POSIX:
CC      = cc
CFLAGS  = -std=c11 -Wall -Wextra -O3 -mcx16 -pthread #-DDEBUG
LDFLAGS = -pthread
#LDLIBS  = -latomic

C= $(wildcard *.c)
H= $(wildcard *.h)
PREAMBULE_SRCS := preambule.c
POSIX_SRCS := $(filter-out %preambule.c %Atomic.c %TestAndSet.c, $(C))
ATOMIC_SRCS := $(filter-out %preambule.c %POSIX.c %TestAndSet.c, $(C))
TESTANDSET_SRCS := $(filter-out %preambule.c %POSIX.c %Atomic.c, $(C))
DEPS= $(H:.h)
PREAMBULE_OBJS= $(PREAMBULE_SRCS:.c=.o)
POSIX_OBJS= $(POSIX_SRCS:.c=.o)
ATOMIC_OBJS= $(ATOMIC_SRCS:.c=.o)
TESTANDSET_OBJS= $(TESTANDSET_SRCS:.c=.o)

preambule: $(PREAMBULE_OBJS) $(DEPS)
	$(CC) $(LDFLAGS) -o preambule $(PREAMBULE_OBJS) $(LDLIBS)

posix: $(POSIX_OBJS) $(DEPS)
	$(CC) $(LDFLAGS) -o multitaskingAccumulatorPosix $(POSIX_OBJS) $(LDLIBS)

atomic: $(ATOMIC_OBJS) $(DEPS)
	$(CC) $(LDFLAGS) -o multitaskingAccumulatorAtomic $(ATOMIC_OBJS) $(LDLIBS)

testandset: $(TESTANDSET_OBJS) $(DEPS)
	$(CC) $(LDFLAGS) -o multitaskingAccumulatorTestAndSet $(TESTANDSET_OBJS) $(LDLIBS)

clean:
	rm -f preambule multitaskingAccumulatorPosix multitaskingAccumulatorAtomic multitaskingAccumulatorTestAndSet $(PREAMBULE_OBJS) $(POSIX_OBJS) $(ATOMIC_OBJS) $(TESTANDSET_OBJS)

runpreambule: clean preambule
	./preambule

runposix: clean posix
	./multitaskingAccumulatorPosix

runatomic: clean atomic
	./multitaskingAccumulatorAtomic

runtestandset: clean testandset
	./multitaskingAccumulatorTestAndSet