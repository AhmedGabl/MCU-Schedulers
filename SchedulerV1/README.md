# MCU Scheduler - Version 1
https://github.com/AhmedGabl/MCU-Schedulers/assets/63268983/1805b419-9d3b-4df9-bb56-c28c306882a0

## Overview
This project demonstrates a basic task scheduler for microcontrollers (MCUs). The main file (`main.c`) initializes the scheduler and creates three LED tasks. The scheduler, implemented in `OS_program.c`, manages task execution with fixed periodicity, running all tasks at the beginning.

## How to Use

1. **Task Creation:**
   - Open `main.c` and use `OS_voidCreateTask` to create LED tasks.
   - Adjust task periodicity (time between executions) and functions based on your requirements.

2. **Start the Scheduler:**
   - Call `OS_voidStartScheduler` in `main.c` to begin task execution.

### Note:
- This scheduler operates without an initial delay, running all tasks at the beginning.

## Contributors

- Author: Ahmed Abogabl
