#include <stdio.h>
#include <math.h>

// Definindo a função f(x)
double f(double x) {
    // log base 10
    return log10(x*x + 1) - pow((x - 6), 2) + 3;
}

int main() {
    double a = 3.0, b = 4.0; // intervalo inicial
    double fa = f(a), fb = f(b);
    double tol = 0.1; // tolerância pedida
    double m, fm;
    int max_iter = 100, iter = 0;

    // Verificar se há raiz no intervalo
    if (fa * fb > 0) {
        printf("Nao ha garantia de raiz no intervalo [%.2f, %.2f]\n", a, b);
        return 1;
    }

    printf("Iter\t a\t\t b\t\t m\t\t f(m)\n");
    while ((b - a) / 2.0 > tol && iter < max_iter) {
        m = (a + b) / 2.0;  // ponto médio
        fm = f(m);

        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\n", iter+1, a, b, m, fm);

        if (fabs(fm) < tol) { // raiz encontrada
            break;
        }

        if (fa * fm < 0) {
            b = m;
            fb = fm;
        } else {
            a = m;
            fa = fm;
        }

        iter++;
    }

    printf("\nA raiz aproximada esta em x = %.4f\n", m);
    return 0;
}
