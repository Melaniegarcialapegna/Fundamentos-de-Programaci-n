
import vectores

#Se le pasan los 3 vectores a la funcion "calcular_area_triangulo". Vector 1: (x1,y1,z1), vector 2: (x2,y2,z2), vector 3: (x3,y3,z3).
#(a1,a2,a3) es el vector que devuelve la diferencia entre (x1,y2,z1) y (x2,y2,z2).
#(b1,b2,b3) es el vector que devuelve la diferencia entre (x1,y2,z1) y (x3,y3,z3).
#Se hace el producto vectorial con los vectores que obtuve al hacer las diferencias y obtengo el vector (c1,c2,c3).
#Finalmente le paso el vector (c1,c2,c3) a la funcion norma y una vez pasado por esta, se divide al resultado por dos para obtener el área del triangulo.
def calcular_area_triangulo(x1, y1, z1, x2, y2, z2, x3, y3 ,z3):
	a1,a2,a3 = vectores.diferencia(x1, y1, z1, x2, y2, z2)
	b1,b2,b3 = vectores.diferencia(x1, y1, z1, x3, y3, z3)
	c1,c2,c3 = vectores.calcular_producto_vectorial(a1, a2, a3, b1, b2, b3)
	n = vectores.norma(c1, c2, c3)
	return n/2

print(calcular_area_triangulo(5, 8, -1, -2, 3, 4, -3, 3, 0))
print(calcular_area_triangulo(-2, 0, 2, -5, 2, 0, 6, -3, 7))
print(calcular_area_triangulo(1, 3, 2, 6, -1,-1, 6, 2, 1))