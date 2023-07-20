# https://app.codesignal.com/challenge/uT5NtaZw97JwYtvjQ

N=numpy
x,*I=N.r_[eval(dir()[1])]
i=[*N.argsort(x)]

while i[1:]:
    I+=[*{*map(i.pop,[N.argmin(N.diff(x[i]))]*2)}],
return I
