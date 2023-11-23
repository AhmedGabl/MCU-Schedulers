# MCU Scheduler - Version 3

## Overview

This version of the MCU Scheduler extends the functionality to handle multiple tasks with the same priority. The main file (`main.c`) demonstrates the scheduler's capabilities by creating LED tasks with various priorities and initial delays. The scheduler, implemented in `OS_program.c`, manages the execution of tasks with consideration for priority and initial delay.

## Handling Same Priority Tasks

In scenarios where tasks share the same priority level, this version allows you to create and manage multiple tasks concurrently. This can be beneficial for systems with parallel processes that need to be executed simultaneously.

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
