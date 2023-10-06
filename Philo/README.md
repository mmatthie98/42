this project is a simulation using threads, the project was about the utilisation of the multithreading, the difficult was to be able to organize the code to make the error fix more easy.

The race condition was a critical point of this project because with multithreading you need to be organised and you can't leave something to the luck.

here is the main informations about the project :

- Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]

- number_of_philosophers: The number of philosophers and also the number
of forks.

- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

- time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.

- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

- number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.