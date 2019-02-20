"""
ID: nbjarvi1
LANG: PYTHON3
TASK: gift1
"""

with open("gift1.in", "r") as fin:
    n_participants = int(fin.readline())
    participant_list = [
        fin.readline().strip()
        for _ in range(n_participants)]
    participants = {
        participant:0
        for participant in participant_list}
    for _ in range(n_participants):
        giver = fin.readline().strip()
        money, n_receivers = fin.readline().strip().split()
        money, n_receivers = int(money), int(n_receivers)
        for _ in range(n_receivers):
            participants[fin.readline().strip()] += money // n_receivers
        if n_receivers != 0:
            participants[giver] -= money // n_receivers * n_receivers
    result = "\n".join(map(
        lambda i: "{} {}".format(*i),
        sorted(
            participants.items(),
            key=lambda i: participant_list.index(i[0]))))

    with open("gift1.out", "w") as fout:
        fout.write(result)
        fout.write("\n")
