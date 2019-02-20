"""
ID: nbjarvi1
LANG: PYTHON3
TASK: milk
"""

def read2int(handle):
    a, b = handle.readline().strip().split()
    return int(a), int(b)

with open("milk.in", "r") as fin:
    need, n_farmers = read2int(fin)

    data = sorted(
        [read2int(fin) for _ in range(n_farmers)],
        key=lambda i: i[0])

    total_price = 0
    current_need = need
    for price, units in data:
        bought = min(units, current_need)
        current_need -= bought
        total_price += bought * price
        if current_need == 0:
            break

    with open("milk.out", "w") as fout:
        fout.write("{}\n".format(total_price))
