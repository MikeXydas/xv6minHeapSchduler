# xv6minHeapScheduler
Implementing a minHeapScheduler replacing the default round-robin

The files if you would like to test them, should be pasted in a clean xv6 directory I have only added new files and default xv6 files that I have changed

minHeapScheduler explanation:

Every process has its own priority produced by this formula: priority = runningTime / (currentTime - creationTime)
Each priority is stored in a minHeap. The process with the smallest arithmetic priority will be the root of the minHeap
and the next one to be scheduled

I have also added an expanded PS command (myPS) and some workloads (some of them perform heavy input, some of them are CPU intensive and some of them are mixed)
