from scipy import stats
fert_A = [20, 22, 19, 24, 21]
fert_B = [28, 27, 30, 26, 29]
fert_C = [18, 20, 17, 19, 21]
f_stat, p_value = stats.f_oneway(fert_A, fert_B, fert_C)
print('F-statistic :', round(f_stat, 3))
print('p-value :', round(p_value, 6))