import numpy as np
from scipy import stats

np.random.seed(1)
scores = np.random.normal(loc=78, scale=10, size=40) # n = 40 exam scores
pop_mean = 75 # claimed population mean
pop_std = 10 # known population standard deviation
n = len(scores)
sample_mean = scores.mean()
z_stat = (sample_mean - pop_mean) / (pop_std / np.sqrt(n))
p_value = 2 * (1 - stats.norm.cdf(abs(z_stat))) # two-tailed

print('Sample mean :', round(sample_mean, 2))
print('Z-statistic :', round(z_stat, 3))
print('p-value :', round(p_value, 4))