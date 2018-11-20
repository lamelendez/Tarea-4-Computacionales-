import numpy as np
import matplotlib.pyplot as plt
temp_fi1=np.genfromtxt("fi1o.txt",delimiter=",",filling_values="2" )
temp_fi2=np.genfromtxt("fi2o.txt",delimiter=",",filling_values="2" )
temp_fi3=np.genfromtxt("fi3o.txt",delimiter=",",filling_values="2" )
temp_fi4=np.genfromtxt("fi4o.txt",delimiter=",",filling_values="2" )

plt.imshow(temp_fi1)
plt.savefig("fi1o.jpg")
plt.clf()
plt.imshow(temp_fi2)
plt.savefig("fi2o.jpg")
plt.clf()
plt.imshow(temp_fi3)
plt.savefig("fi3o.jpg")
plt.clf()
plt.imshow(temp_fi4)
plt.savefig("fi4o.jpg")
plt.clf()

temp_ab1=np.genfromtxt("ab1o.txt",delimiter=",",filling_values="2" )
temp_ab2=np.genfromtxt("ab2o.txt",delimiter=",",filling_values="2" )
temp_ab3=np.genfromtxt("ab3o.txt",delimiter=",",filling_values="2" )
temp_ab4=np.genfromtxt("ab4o.txt",delimiter=",",filling_values="2" )

plt.imshow(temp_ab1)
plt.savefig("ab1o.jpg")
plt.clf()
plt.imshow(temp_ab2)
plt.savefig("ab2o.jpg")
plt.clf()
plt.imshow(temp_ab3)
plt.savefig("ab3o.jpg")
plt.clf()
plt.imshow(temp_ab4)
plt.savefig("ab4o.jpg")
plt.clf()

temp_pe1=np.genfromtxt("pe1o.txt",delimiter=",",filling_values="2" )
temp_pe2=np.genfromtxt("pe2o.txt",delimiter=",",filling_values="2" )
temp_pe3=np.genfromtxt("pe3o.txt",delimiter=",",filling_values="2" )
temp_pe4=np.genfromtxt("pe4o.txt",delimiter=",",filling_values="2" )

plt.imshow(temp_pe1)
plt.savefig("pe1o.jpg")
plt.clf()
plt.imshow(temp_pe2)
plt.savefig("pe2o.jpg")
plt.clf()
plt.imshow(temp_pe3)
plt.savefig("pe3o.jpg")
plt.clf()
plt.imshow(temp_pe4)
plt.savefig("pe4o.jpg")
plt.clf()


v10=np.loadtxt("10v.txt")
v20=np.loadtxt("20v.txt")
v30=np.loadtxt("30v.txt" )
v40=np.loadtxt("40v.txt" )
v45=np.loadtxt("45v.txt" )
v50=np.loadtxt("50v.txt")
v60=np.loadtxt("60v.txt")
v70=np.loadtxt("70v.txt")

print(v10)
vx10=v10[:,2]
vx20=v20[:,2]
vx30=v30[:,2]
vx40=v40[:,2]
vx50=v50[:,2]
vx60=v60[:,2]
vx70=v70[:,2]
vx45=v45[:,2]

vy10=v10[:,3]
vy20=v20[:,3]
vy30=v30[:,3]
vy40=v40[:,3]
vy50=v50[:,3]
vy60=v60[:,3]
vy70=v70[:,3]
vy45=v45[:,3]


plt.plot(vx45,vy45)
plt.savefig("45vtw.jpg")
plt.clf()

plt.plot(vx10,vy10)
plt.plot(vx20,vy20)
plt.plot(vx30,vy30)
plt.plot(vx40,vy40)
plt.plot(vx50,vy50)
plt.plot(vx60,vy60)
plt.savefig("totvtw.jpg")
plt.clf()
