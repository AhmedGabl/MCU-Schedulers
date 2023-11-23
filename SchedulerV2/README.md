# MCU Scheduler - Version 2

## Overview

This version of the MCU Scheduler builds upon the basic scheduler by introducing an initial delay for tasks. The main file (`main.c`) initializes the scheduler and creates three LED tasks with varying initial delays. The scheduler, implemented in `OS_program.c`, manages task execution with initial delays and fixed periodicity.

## Why Use Initial Delays?

In scenarios where precise synchronization or avoiding excessive CPU load is crucial, the introduction of initial delays provides several benefits:

1. **Avoiding CPU Spikes:**
   - Initial delays help stagger the execution of tasks, preventing simultaneous spikes in CPU usage. This is particularly useful in systems where evenly distributed processing is essential for stability.

2. **Synchronization:**
   - Tasks with initial delays can be synchronized to start at specific intervals, ensuring coordinated execution and reducing the likelihood of conflicts.

3. **Load Balancing:**
   - By strategically setting initial delays, you can achieve a more balanced distribution of CPU load over time, preventing peaks that could impact overall system performance.

## How to Use

1. **Task Creation:**
   - Open `main.c` and use `OS_voidCreateTask` to create LED tasks.
   - Adjust task periodicity (time between executions) and initial delays based on your requirements.

2. **Start the Scheduler:**
   - Call `OS_voidStartScheduler` in `main.c` to begin task execution.

3. **Additional Functions:**
   - `OS_voidDeleteTask`: Deletes a task.
   - `OS_voidSuspendTask`: Suspends a task for a specified time.
   - `OS_voidResumeTask`: Resumes a suspended task.
   - `OS_u8GetTaskState`: Retrieves the state of a task.

## Contributors

- Author: Ahmed Abogabl
