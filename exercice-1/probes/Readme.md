Firstly: change the path for lines 12 and 18 of each stp files. This is the absolute path of your executables.

Then launch the stap scripts.
- sudo stap getProducerCountPosix.stp
- sudo stap getProducerCountAtomic.stp
- sudo stap getProducerCountTestAndSet.stp

Run your executables from the runX script to run your executables several times.
- ./probes/runX.sh mySoftwarePosix 10
- ./probes/runX.sh mySoftwareAtomic 10
- ./probes/runX.sh mySoftwareTestAndSet 10