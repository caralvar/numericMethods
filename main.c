#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("******************************************************************\n");
    printf("** Tarea programadada de Metodos Numericos                      **\n");
    printf("** IE-0305 Matematicas Superiores                               **\n");
    printf("** Prof. Ing. Jeancarlo Mendez Calvo                            **\n");
    printf("** II-2016 - Grupo 01                                           **\n");
    printf("** Estudiantes:                                                 **\n");
    printf("**        -Josue Gomez     (B52994)                             **\n");
    printf("**        -Carlos Alvarado (B50339)                             **\n");
    printf("******************************************************************\n");
    printf("\n");
    printf("Problema 1 (Metodo de Newton-Raphson)                        \n\n");
    printf("A continuacion se encontrara la solucion(es) a la siguiente ecuacion:\n\n");
    printf("2sin(3x)+0,25cos(5x)-x^(2)*e^(x)+e^(-x) = 0\n\n");
    printf("para esto se utilizara el metodo de Newton-Raphson para encontrar\n");
    printf("raices de funciones, por lo tanto se encontraran las raices de la\n");
    printf("siguiente funcion: f(x)=2sin(3x)+0,25cos(5x)-x^(2)*e^(x)+e^(-x), lo\n");
    printf("que es equivalente a resolver la ecuacion anteriormente mencionada.\n\n");

    //Declaracion de funciones utiles correspondientes al problema 1
    //Esta es la funcion para obtener imagenes de la funcion del problema 1
double funcion_problema_1(double x){
    double y = 2*sin(3*x) + (0.25)*cos(5*x)-(x*x)*exp(x) + exp(-1*x);
    return y;
}
    //Esta es la funcion para obtener imagenes de la derivada de la funcion del problema 1
double derivada_problema_1(double x){       //para este metodo es necesario conocer la derivada de la funcion
    double y = 6*cos(3*x) - (1.25)*sin(5*x)-(x*x)*exp(x)-(2*x)*exp(x) - exp(-1*x);
    return y;
}
    //Ahora se realizan pruebas con distintos valores iniciales para obtener la solucion a
    //la ecuacion por el metodo de Newton-Raphsord

    double valor_inicial = 1;   //Se declara el valor inicial de prueba
    printf("Valor inicial = %f\n",valor_inicial);
    double e = 1;               //Esta es la variable que va a determinar cuando finalizar las iteraciones
    double xi1;                 //Valor obtenido despues de la primer iteracion
    int count = 1;              //Cuenta para mostrar al usuario cuantas iteraciones fueron necesarias

    while(e>0.0000001){         //Se utiliza un while para realizar las iteraciones, este va a finalizar cuando e<0.0000001
        printf("Iteracion %d\n",count);
        xi1 = valor_inicial - (funcion_problema_1(valor_inicial)/derivada_problema_1(valor_inicial));
        printf("Xi+1 = %f\n",xi1);
        e = fabs(xi1-valor_inicial);
        valor_inicial=xi1;
        count++;
    }
    printf("Una de las soluciones a la ecuacion es: %f\n\n",xi1);

    valor_inicial = 0;      //Nuevo valor inicial
    printf("A continuacion se realizara otra prueba con otro valor inicial\n para determinar otra solucion:\n\n");
    printf("Valor inicial = %f\n",valor_inicial);
    count = 1;
    e = 1;

    while(e>0.0000001){
        printf("Iteracion %d\n",count);
        xi1 = valor_inicial - (funcion_problema_1(valor_inicial)/derivada_problema_1(valor_inicial));
        printf("Xi+1 = %f\n",xi1);
        e = fabs(xi1-valor_inicial);
        valor_inicial=xi1;
        count++;
    }
    printf("Una de las soluciones a la ecuacion es: %f\n\n",xi1);

    valor_inicial = -1;     //Nuevo valor inicial
    printf("A continuacion se realizara otra prueba con otro valor inicial\n para determinar otra solucion:\n\n");
    printf("Valor inicial = %f\n",valor_inicial);
    count = 1;
    e = 1;

    while(e>0.0000001){
        printf("Iteracion %d\n",count);
        xi1 = valor_inicial - (funcion_problema_1(valor_inicial)/derivada_problema_1(valor_inicial));
        printf("Xi+1 = %f\n",xi1);
        e = fabs(xi1-valor_inicial);
        valor_inicial=xi1;
        count++;
    }
    printf("Una de las soluciones a la ecuacion es: %f\n\n",xi1);

    printf("******************************************************************\n");

    /////////////////////////////////////////////////////////////////////////////////
    //Inicio del problema 2 de la regla de Simpson de 1/3
    printf("Problema 2 (Regla de Simpson de 1/3 con segmentos multiples)\n\n");
    printf("Para este problema se obtendra un valor aproximado de una integral  \n");
    printf("que va de 2 a 10 donde f(x)=(e^(-0,3*t))/(ln(t)*sec(4+t)) \n");

    //Declaracion de la funcion que entrega la imagen de la funcion por integrar
double funcion_integral (double x){
    double y = (exp(-0.3*x))/(log(x)*(1/cos(4+x)));
    return y;
}
    double limite_inferior = 2;     //Se define el limite inferior de la integral
    double limite_superior = 10;    //Se define el limite superior de la integrall
    int N = 100;                    //Cantidad de segmentos que se van a utilizar
    double h = (limite_superior - limite_inferior)/N;   //h definido en la regla de simpson
    double resultado_integral = 0;  //Variable que va a alojar el resultado de la integral
    int i;                          //Variable para realizar las iteraciones del for

    for(i = 0; i<N ; i++ ){
        resultado_integral = resultado_integral + (h/3)*((funcion_integral(limite_inferior + h*i) +            //Se aplica la formula de Simpson
            4*funcion_integral(limite_inferior + h*i + h/2) + funcion_integral(limite_inferior + h*(i+1)))/2); //de manera recursiva sobre la
    }                                                                                                          //variable resultado_integral

    printf("\nEl resultado de la integral dividiendo en 100 partes es: I = %f\n", resultado_integral);
    printf("\n******************************************************************\n");

    /////////////////////////////////////////////////////////////////////////////////////
    //Inicio del problema 3 del metode de Runge-Kutta de cuarto orden
    printf("\nProblema 3 (Metode de Runge-Kutta de cuarto orden)\n");
    printf("\nA continuacion se utilizara el metodo de Runge-Kutta para encontrar \n");
    printf("la solucion a la ecuacion (dy/dx)=(2x-sin(y))/(xcos(y)) para x = 1,5  \n");
    printf("(se considera que (xo,yo)=(1,0))\n");

    //Se declara la funcion que devuelve la imagen de la funcion dependiente de x,y en cuestion
    //para poder resolver la ecuacion diferencial con este metodo
double funcion_problema_3 (double x,double y){
    double z = (2*x - sin(y))/(x*cos(y));
    return z;
}
    //se determina el par inicial (xo,yo)
    double xo = 1;
    double yo = 0;
    //Se determina el paso, en este caso se escogio 0,25 porque implica que se necesitan
    //dos pasos para obtener la solucion, ya que el x en el que se va a evaluar es 1,5
    //y el xo es 1 entonces x=1+2h, esto brinda un resultado mas exacto.
    h = 0.25;

    printf("\nSe escoge un tamaño de paso de 0,25 por lo que se obtendra la solucion\n");
    printf("despues del segundo paso, ya que x0 = 1\n\n");

    //A continuacion se obtienen los k del primer paso de acuerdo al metodo utilizado
    printf("\nPrimer paso\n");
    double k1 = funcion_problema_3(xo,yo);
    printf("k1 = %f\n",k1);
    double k2 = funcion_problema_3(xo + h/2, yo + k1*h/2);
    printf("k2 = %f\n",k2);
    double k3 = funcion_problema_3(xo + h/2, yo + k2*h/2);
    printf("k3 = %f\n",k3);
    double k4 = funcion_problema_3(xo + h, yo + k3*h);
    printf("k4 = %f\n",k4);
    double y1 = yo + (k1 + 2*(k2 + k3) + k4)*h/6;      //Se obtiene el y1 correspondiente al x1 del primer paso
    printf("Entonces (x1,y1) = (%f,%f)\n",xo+h,y1);

    //Se obtienen los k del segundo paso (ultimo paso), se utilizan x1 y y1 obtenidos en el primer paso
    //como valores iniciales
    printf("\nSegundo paso\n");
    k1 = funcion_problema_3(xo + h,y1);
    printf("k1 = %f\n",k1);
    k2 = funcion_problema_3(xo + h + h/2, y1 + k1*h/2);
    printf("k2 = %f\n",k2);
    k3 = funcion_problema_3(xo + h + h/2, y1 + k2*h/2);
    printf("k3 = %f\n",k3);
    k4 = funcion_problema_3(xo + 2*h, y1 + k3*h);
    printf("k4 = %f\n",k4);

    double y2 = y1 + (k1 + 2*(k2 + k3) + k4)*h/6;   //El y2 obtenido despues del segundo paso es el
                                                    //correspondiente a x=1,5 y por ende la solucion
                                                    //del problema

    printf("\nEl resultado de la funcion que es solucion de la e.d evaluada \nen 1,5 es: %f\n", y2);
    printf("\n******************************************************************\n");

return 0;}

