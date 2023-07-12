# https://app.codesignal.com/challenge/CxBTQDQwNuicbWNp7

import ipaddress as I

n=I.ip_interface(*eval(dir()[1]))
e=n.network
return [".".join(f'{y:08b}' for y in z.packed) + f' {z}' for z in [n.ip,n.netmask,e[0],e[1],e[-2],e[-1]]]
