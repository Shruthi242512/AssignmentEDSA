# Earthquake Rescue Robot Coordinator – CS Assignment

**Course:** Elementary Data Structures and Algorithms  
**Assignment Question 8**

## Overview

This project simulates a disaster relief coordination system using core data structures like **queues, stacks, arrays, singly/doubly/circular linked lists**. Robots are assigned to missions, tracked for damage and repair, and redeployed based on urgency.

## Structure

### a) Mission and Urgency — Queue + Stack

- **Queue** simulates mission requests from survivors.
- **Stack** manages urgent tasks in **LIFO** order.
- Six tasks: `Scanner`, `Digger`, `Lift`, `Light`, `Drone`, `Cutter`.
- Tasks are enqueued, dequeued, and pushed to the stack.
- Stack is popped to determine the order of execution.

#### Creativity Bonus 💡
LIFO works best in urgency. If "Cutter" is stacked last, it's accessed first to clear debris, giving way to other robots. This priority ensures faster access to trapped survivors.

---

### b) Rescue Log Unit — Fixed Array

- Uses a **fixed-size array** (size 6) for mission logging.
- Inserts 8 missions (`Mis1` to `Mis8`) to simulate overflow.
- When full, the system reports the oldest logged mission.

#### Creativity Bonus 💡
Reporting the oldest mission keeps rescue teams informed of survivor status. It ensures no mission goes unreported due to memory constraints.

---

### c) Damaged Robot Tracker — Linked Lists

- **Singly Linked List** for damaged robots: `Digger`, `Drone`.
- `Digger` is repaired and moved to a **Doubly Linked List** for inspection.
- Forward and backward traversal ensures maintenance quality.

#### Creativity Bonus 💡
`Digger` suffered a crushed arm due to a collapsed tunnel. Techs replaced the joint hydraulics and tested movement in reverse to validate symmetry.

---

### d) Priority Redeployment — Circular Linked List

- **Circular Linked List** manages `Scanner` and `Lift` for fast redeployment.
- Traversed twice to simulate continuous operation in loops.

#### Creativity Bonus 💡
`Lift` is upgraded with a thermal camera to detect survivor body heat in rubble. `Scanner` syncs with it to plan pathfinding in zero visibility.

---

## Technologies

- **Language:** C (or Pseudocode-based simulation)
- **Data Structures Used:**
  - Queue
  - Stack
  - Fixed Array
  - Singly Linked List
  - Doubly Linked List
  - Circular Linked List

## Author

- **Name:** Shruthi Pullela  
- **Roll Number:** ME24B1064    
- **Batch:** 5  
