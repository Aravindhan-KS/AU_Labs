import numpy as np, pandas as pd
from statsmodels.stats.multicomp import pairwise_tukeyhsd

fert_A = [20, 22, 19, 24, 21]
fert_B = [28, 27, 30, 26, 29]
fert_C = [18, 20, 17, 19, 21]

yields = fert_A + fert_B + fert_C
groups = ['A']*5 + ['B']*5 + ['C']*5
tukey = pairwise_tukeyhsd(endog=yields, groups=groups, alpha=0.05)
print(tukey)
