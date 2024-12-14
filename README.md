# 🚀 **C/C++ Projects Overview** 🌟

This README introduces a collection of **C** and **C++** programs that showcase a variety of algorithms, utilities, and problem-solving techniques. Each project is designed to highlight key programming concepts. Let's dive in! 🌊

---

## 📂 **Project List**

### 1️⃣ **Airline Ticket Booking System** ✈️
**File:** `airlines.c`

Manage flight bookings with ease! This system provides:
- ✍️ **Booking Tickets**: Reserve seats on flights (flights available: `102`, `311`, `444`, and `519`).
- ❌ **Cancel Tickets**: Remove passengers from reserved seats.
- ✅ **View Free Seats**: Check availability on each flight.
- 📋 **List Passengers**: Display a list of all booked passengers.
- 💾 **File Persistence**: Saves and retrieves booking details from `data_air.txt`.

**Menu Example**:
```text
a) Number of free seats
b) List of free seats
c) List of passengers
d) Book the Ticket
e) Cancel booking
f) Return to main menu


---

### 2️⃣ **Matrix Operations Menu** 🧮
**File:** `matrix_operations_menu.c`

A collection of matrix-based tasks, including:
- 🟢 **Task 1**: Find the geometric mean of positive elements on the secondary diagonal of a square matrix.
- ❌ **Task 2**: Remove all zero elements from a predefined array.
- 🔀 **Task 3**: Identify and modify the smallest number among three inputs, and demonstrate pointer swapping.

**Menu Example**:
```text
1. Geometric mean of positive elements on secondary diagonal
2. Remove zeros from array
3. Modify the smallest number among three
0. Exit
```

---

### 3️⃣ **Calculator** 🔢
**File:** `Calculator.c`

A robust **scientific calculator** packed with features:
- ➕ **Basic Arithmetic**: Add, multiply, divide, and calculate powers or roots.
- 📉 **Logarithms**: Calculate logarithms with custom bases.
- 🎯 **Trigonometric Functions**: Sine, cosine, tangent, and cotangent.
- 📋 **Extras**: Rounds numbers and provides calculator metadata.

**Sample Menu**:
```text
1. Add numbers
2. Multiply numbers
3. Divide numbers
4. Power of numbers
5. Root of numbers
6. Logarithm calculation
7. Calculate sine
8. Calculate cosine
9. Calculate tangent
10. Calculate cotangent
11. Round number
12. About Calculator
13. Exit
```

---

### 4️⃣ **Matrix Tasks Menu** 📉
**File:** `array_matrix_tasks_menu.c`

This project focuses on advanced matrix operations:
- 🔍 **Task 1**: Find the minimum element in each column of a matrix.
- 🟰 **Task 2**: Identify pairs of matrix elements whose product equals `1`.

---

### 5️⃣ **Character Pairing** 🧩
**File:** `character_pairing.c`

- **Objective**: Pair characters from two input strings and display them side by side. Perfect for analyzing relationships between characters in two sequences. 🌟

---

### 6️⃣ **Check Digits** 🔢
**File:** `check_digits.c`

- 🔍 **Validation Tool**: Determine whether a user-input string contains only numeric digits.
- Example Input/Output:
  ```
  Input: "12345"
  Output: The string contains only digits.
  ```

---

### 7️⃣ **File-Based Word Management** 📂
**File:** `lab_8.c`

Effortlessly manage words in a file! Here's what this program does:
- 🖊️ **Add Words**: Input a list of comma-separated words to save in the file (`123.txt`).
- 🔢 **Track Counts**: Automatically manage a counter for the total number of words.
- 🛡️ **Ensure Integrity**: Updates the file while ensuring its structure is preserved.

---

## 🎯 **How to Run**
Each project can be run separately. Follow these steps:

1. **Compile the program** using a compatible compiler:
   ```bash
   gcc -o program_name source_file.c
   ```
   or
   ```bash
   g++ -o program_name source_file.cpp
   ```
2. **Execute** the compiled file:
   ```bash
   ./program_name
   ```

---

## 🧠 **Skills and Concepts Covered**
- 🔧 **Dynamic Memory Management**: Allocating and freeing memory dynamically (e.g., `malloc` and `free` in C).
- 📂 **File Operations**: Open, read, write, and update files for persistent data storage.
- ⚙️ **Pointers**: Demonstrate advanced use of pointers for tasks like swapping values and accessing arrays.
- 🗂️ **Data Structures**: Use of `struct` to handle complex records like airline tickets.
- 📊 **Matrix Manipulations**: Solve computational problems involving multidimensional arrays.

---
