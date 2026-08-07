from scipy import stats
before = [62, 65, 70, 58, 74, 68, 60, 72, 66, 64]
after = [68, 70, 74, 65, 78, 72, 66, 75, 70, 69]
t_stat, p_value = stats.ttest_rel(after, before)
print('T-statistic :', round(t_stat, 3))
print('p-value :', round(p_value, 5))