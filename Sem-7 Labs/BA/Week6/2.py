import numpy as np
from scipy import stats

dept_A = [52000, 54500, 51000, 58000, 53500, 56000, 50500, 55500]
dept_B = [61000, 59500, 63000, 60500, 62500, 58500, 64000, 60000]

t_stat, p_value = stats.ttest_ind(dept_A, dept_B, equal_var=False) # Welch's t-test
print('T-statistic :', round(t_stat, 3))
print('p-value :', round(p_value, 5))