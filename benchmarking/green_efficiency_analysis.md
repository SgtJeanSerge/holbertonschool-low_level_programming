# Measurement Methodology
The all test was perform on a CPU Intel(R) Core(TM) Ultra 7 265K (2+8+10) @ 4.60 GHz packed in a docker container on ubuntu 24.04 
The measurement are based on time extract with cpu clicks by the clock command in a C program.

# Observed Performance Differences
We can see clearly the impact of different algorithms leading to the same result. Task 1 is the brightest example.
On 3 runs we concluded of a hudge gap of performance between the two algorithm ; the naive one 24000 time less efficient than the Single-pass one.

# Relation Between Runtime and Energy Consumption
Accounting the informations above it seem obvious than the impact on energy consumption can be massive and not only just on computing power but also in time of compute and hit generated who need to be cooldown.
Even if this big gap of performance is invisble on small programs like this one, we can imagin the importance of optimizing the resources for softwares and service with millions of clients and billions of process.

# Limitations of the Experiment
This test are limited by small process and and small amount of tests with uncontroled environement.

# Practical Engineering Takeaway 
This exercice shows the engeneering and knoledge to design efficient algorithms are key. 
It help save ressources, for greener software.
Optimise time of compute for more efficiency and better scalability.
For nice side effect it give a clear code easier to read and maintain. 
