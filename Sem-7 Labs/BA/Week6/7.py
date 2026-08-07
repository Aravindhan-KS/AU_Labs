t_statistic = 2.87
p_value = 0.006
alpha = 0.05

print("t-statistic:", t_statistic)
print("p-value:", p_value)
print("alpha:", alpha)

if p_value < alpha:
    print("\nDecision: Reject the null hypothesis (H0)")
    print("Conclusion: p-value < alpha, so the result is statistically significant at the 5% level. There is sufficient evidence of a real effect/difference\n")
else:
    print("\nDecision   : Fail to reject the null hypothesis (H0)")
    print("Conclusion : p-value >= alpha, so the result is not statistically significant at the 5% level.")