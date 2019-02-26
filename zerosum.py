"""
ID: nbjarvi1
LANG: PYTHON3
TASK: zerosum
"""
N=int(open("zerosum.in").read());open("zerosum.out","w").write("\n".join(s for s in["".join([str(s)for s in list(zip(range(1,N),[" +-"[n//3**i%3]for i in range(N-2,-1,-1)]))for s in s]+[str(N)])for n in range(3**(N-1))]if eval(s.replace(" ",""))==0)+"\n")
