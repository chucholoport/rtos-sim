# Remedial Exercise: Task Starvation Analysis

## Objective

Analyze the behavior of a multitasking FreeRTOS application and identify the cause of an execution problem affecting one of the tasks.

The purpose of this exercise is to practice:

* Task creation and scheduling
* Task priorities
* CPU resource allocation
* Detection of starvation conditions
* Debugging of multitasking systems

---

## Instructions

### Step 1 – Run the application

Compile and execute the provided project in Wokwi.

Observe:

* LED behavior
* Logic analyzer signals
* Serial monitor output

Do not modify the code during this stage.

---

### Step 2 – Analyze the symptoms

Record your observations.

Consider the following questions:

* Which LEDs are operating correctly?
* Is any LED missing activity?
* Are all tasks appearing in the serial output?
* Is the behavior what you expected for a multitasking application?

Write a brief description of the observed symptoms.

---

### Step 3 – Inspect the source code

Read the implementation of:

* `TaskFast()`
* `TaskMedium()`
* `TaskSlow()`

Pay attention to:

* Task priorities
* Infinite loops
* Delay functions
* CPU usage patterns

Try to determine:

* Which task is causing the problem
* Why another task cannot execute correctly

---

### Step 4 – Root cause analysis

Determine:

1. What type of issue is occurring?
2. Why is the scheduler behaving this way?
3. Which task characteristics are responsible for the problem?

Document your reasoning.

---

### Step 5 – Implement a correction

Modify the application so that:

* All tasks execute correctly
* All LEDs show activity
* The scheduler behaves as expected

You may consider:

* Task timing
* CPU yielding mechanisms
* Priority adjustments

---

## Deliverables

Submit:

1. Corrected source code
2. Screenshot of the corrected execution

---

## Expected outcome after correction

After fixing the issue:

* All three LEDs should operate
* Serial monitor should show activity from all tasks
* The multitasking system should behave predictably
* No task should remain starved
