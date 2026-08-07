import numpy as np
from scipy import stats
a = np.array([23, 25, 21, 27, 24, 26, 22])
b = np.array([30, 32, 28, 31, 29, 33, 27])
# ---- manual computation (Welch's t-test, unequal variances) ----
mean_a, mean_b = a.mean(), b.mean()
var_a, var_b = a.var(ddof=1), b.var(ddof=1)
na, nb = len(a), len(b)
t_manual = (mean_a - mean_b) / np.sqrt(var_a/na + var_b/nb)
# Welch–Satterthwaite degrees of freedom
df = (var_a/na + var_b/nb)**2 / (
 (var_a/na)**2/(na-1) + (var_b/nb)**2/(nb-1))
p_manual = 2 * (1 - stats.t.cdf(abs(t_manual), df))
print('Manual -> t = %.4f , p = %.5f , df = %.2f' % (t_manual, p_manual, df))
# ---- library computation ----
t_lib, p_lib = stats.ttest_ind(a, b, equal_var=False)
print('SciPy -> t = %.4f , p = %.5f' % (t_lib, p_lib))