# include <stdio.h>
int main () {
int cla , cat , ant , sal , res ;
printf (" Ingrese la clave del trabajador : ");
scanf (" %d", &cla );
printf (" Ingrese la categoria del empleado : ") ;
scanf (" %d", &cat );
printf (" Ingrese la antiguedad del trabajador en la empresa : ");
scanf (" %d", &ant );
printf (" Ingrese el salario del trabajador : ");
scanf (" %d", &sal );
if (( cat == 3 || cat == 4) && ant > 5) {
res = 1;
} else if ( cat == 2 && ant > 7) {
res = 1;
} else {
res = 0;
}
if ( res == 1) {
printf ("El empleado reune las condiciones necesarias para el puesto .\n");
} else {
printf ("El empleado no reune las condiciones necesarias para el puesto .\n");
}
return 0;
}
