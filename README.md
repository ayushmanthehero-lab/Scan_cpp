# SCAN Disk Scheduling Algorithm

This repository contains a C implementation of the **SCAN Disk Scheduling Algorithm**.  
The SCAN algorithm moves the disk arm in one direction servicing all requests until it reaches the end of the disk, then reverses its direction to service the remaining requests.

---

## 📜 Algorithm Overview

The SCAN disk scheduling algorithm is sometimes called the *Elevator Algorithm* because it works like an elevator:
- It moves in one direction servicing requests in order.
- When it reaches the end, it reverses direction and services requests on the other side.

**Advantages:**
- Provides a more uniform wait time compared to FCFS and SSTF.
- Prevents starvation of requests.

**Disadvantages:**
- May cause delays for requests just behind the head if the head is moving away.

---

## 📂 Files in Repository

- **`scan.c`** → Main C program implementing SCAN algorithm.
- **`SCAN_Disk_Scheduling_Report.pdf`** → Detailed report with code, explanation, and execution output.

---

## ⚙️ How to Compile & Run

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/SCAN-Disk-Scheduling.git
   cd SCAN-Disk-Scheduling
