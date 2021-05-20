![abrabant's stats](https://badge42.herokuapp.com/api/stats/abrabant)
![abrabant's push swap final grade](https://i.imgur.com/goqNL7W.png)

# ft_push_swap

`ft_push_swap` is an algorithm project done at 42 school: the goal is to sort numbers
on a stack using a temporary stack and a **limited and specified set of instructions**.

You can learn more about the project by reading the subject included in this repo.

# Performance

The results presented below have been determined after **1000** tests. The
greater the number of test is, the more accurate the results are going to be.

I decided to stay with 1000 tests as it is good enough to visualize the performance of the
algorithm for a project such as push_swap.

Only meaningful tests are reported below. Tests involving different amounts of
random numbers may give way worse results, as I optimized the project to work
specifically great with specific integer quantities (2, 3, 4, 5, 100 and 500).

2-5 cases are optimized manually (hardcoded).

Bigger cases are handled using a kind of mix between quick sort and insertion sort.
The amount of splitting done is increased for greater quantities, such as 500.

| Amount of random numbers | Min. nb. of instructions | Max. nb. of instructions |
| -------------------------|--------------------------| -------------------------|
| 3                        | 0                        | 2                        |
| 5                        | 0                        | 12                       |
| 100                      | 588                      | 725                      |
| 500                      | 6334                     | 7045                     |
