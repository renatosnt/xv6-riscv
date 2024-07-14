import matplotlib.pyplot as plt

# Updated data based on the provided logs
data = [
    (29, 30, 30),
    (129, 134, 135),
    (245, 254, 253),
    (342, 354, 353),
    (456, 470, 472),
    (571, 588, 591),
    (679, 699, 704),
    (784, 807, 813),
    (894, 923, 929),
    (1007, 1038, 1043),
    (1115, 1149, 1153),
    (1245, 1282, 1290),
    (1393, 1432, 1440),
    (1491, 1537, 1545),
    (1583, 1639, 1649),
    (1689, 1750, 1760),
    (1802, 1863, 1878),
    (1922, 1990, 2003),
    (2019, 2091, 2106),
    (2131, 2207, 2224),
    (2239, 2321, 2338),
    (2337, 2423, 2442),
    (2443, 2537, 2556),
    (2543, 2643, 2662),
    (2643, 2746, 2764),
    (2744, 2856, 2876),
    (2842, 2959, 2979),
    (2939, 3062, 3083),
    (3041, 3171, 3193),
    (3147, 3279, 3303),
    (3253, 3392, 3416),
    (3365, 3509, 3532),
    (3473, 3624, 3649),
    (3582, 3739, 3765),
    (3695, 3855, 3882),
    (3797, 3962, 3987),
    (3908, 4075, 4102)
]

# Prepare the x-axis values (snapshot indices)
x_values = list(range(1, len(data) + 1))

# Separate the data for each process
ticks_proc_4 = [entry[0] for entry in data]
ticks_proc_5 = [entry[1] for entry in data]
ticks_proc_6 = [entry[2] for entry in data]

# Plot the data
plt.figure(figsize=(12, 6))
plt.plot(x_values, ticks_proc_4, label='Process 4 (10 Tickets)', marker='o')
plt.plot(x_values, ticks_proc_5, label='Process 5 (20 Tickets)', marker='o')
plt.plot(x_values, ticks_proc_6, label='Process 6 (30 Tickets)', marker='o')

# Add titles and labels
plt.title('Number of Ticks over Time for Each Process')
plt.xlabel('Snapshot Index')
plt.ylabel('Number of Ticks')
plt.legend()
plt.grid(True)

# Show the plot
plt.show()
