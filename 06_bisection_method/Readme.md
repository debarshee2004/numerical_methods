# Bisection Method

The bisection method is a numerical technique used for finding the root of a real-valued function. It is an iterative algorithm that repeatedly divides an interval in half and selects the subinterval where the function changes sign. The process continues until a sufficiently small interval containing a root is found.

Here's a step-by-step explanation of the bisection method:

1. **Interval Selection**: Initially, you need to choose an interval [a, b] where the function f(x) changes sign. The function should be continuous over the interval.

2. **Midpoint Calculation**: Calculate the midpoint of the interval using the formula:
   \[ c = \frac{a + b}{2} \]

3. **Evaluate the Function**: Evaluate the function f(x) at the midpoint c. If f(c) is very close to zero, then c is considered the root, and the process is terminated.

4. **Update Interval**: Determine the subinterval [a, c] or [c, b] where the sign of f(x) changes. If f(a) and f(c) have opposite signs, then the root lies in the interval [a, c]. Otherwise, it lies in [c, b].

5. **Iteration**: Repeat the process by choosing the midpoint of the new interval and evaluating the function until the interval becomes sufficiently small or until a predefined number of iterations are reached.

The bisection method has several advantages, including simplicity and guaranteed convergence to a root if the initial interval is chosen correctly. However, it also has limitations, such as relatively slow convergence compared to some other methods and the requirement of an initial interval where the function changes sign.

The algorithm is based on the Intermediate Value Theorem, which states that if a continuous function takes on different signs at the endpoints of an interval, it must also take on every value in between, including zero. The bisection method utilizes this principle to systematically narrow down the interval containing the root.
