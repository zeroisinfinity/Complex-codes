def magic_swap(alpha , beta):
    alpha = alpha ^ beta
    beta = beta ^ alpha
    alpha = alpha ^ beta
    return alpha , beta

print(magic_swap(10,20))