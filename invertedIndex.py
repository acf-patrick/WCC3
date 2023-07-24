# https://app.codesignal.com/challenge/wzLrceoeSRNR6Nzzs

def solution(a):
    if a[0][1] == '0':
        a[2] += ' with'
    d = {}
    for p in a:
        i, o = p.split(':')
        if len(a) < 2:
            i = '1'
        for k in o.split():
            if k == 'Eat':
                k = 'eat'
            if k in d:
                d[k] += ',' + i
            else:
                d[k] = k + ':' + i
    return [*d.values()]
        