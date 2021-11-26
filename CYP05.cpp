// CYP05. Programa calificaciones de alumnos. 


#include <stdio.h>

int main()
{
	int NumeroDeCalificaciones;
	int NumeroCuenta[2000];
	double calificaciones[2000];

	scanf_s("%i", &NumeroDeCalificaciones);

	for (int i = 0; i < NumeroDeCalificaciones; i++)
	{
		scanf_s("%i %lf", &NumeroCuenta[i], &calificaciones[i]);
	}

	for (int i = 0; i < NumeroDeCalificaciones-1; i++)
	{
		for (int cantidad = 0; cantidad < NumeroDeCalificaciones-1; cantidad++) {
			if (NumeroCuenta[cantidad] > NumeroCuenta[cantidad + 1]) {

				int NumeroCuentaTemporal = NumeroCuenta[cantidad];
				double CalificacionTemporal = calificaciones[cantidad];

				NumeroCuenta[cantidad] = NumeroCuenta[cantidad + 1];
				NumeroCuenta[cantidad + 1] = NumeroCuentaTemporal;

				calificaciones[cantidad] = calificaciones[cantidad + 1];
				calificaciones[cantidad + 1] = CalificacionTemporal;
			}
		}
	}
	for (int i = 0; i < NumeroDeCalificaciones - 1; i++) {
		for (int cantidad = 0; cantidad < NumeroDeCalificaciones - 1; cantidad++) {

			if (calificaciones[cantidad] < calificaciones[cantidad + 1] && NumeroCuenta[cantidad] == NumeroCuenta[cantidad + 1]) {
				int NumeroCuentaTemporal = NumeroCuenta[cantidad];
				double calificacionTemporal = calificaciones[cantidad];

				calificaciones[cantidad] = calificaciones[cantidad + 1];
				calificaciones[cantidad + 1] = calificacionTemporal;
			}
		}
	}

	int CantidadAlumnos = 0;
	for (int i = 0; i < NumeroDeCalificaciones; i++) {

		if (NumeroCuenta[i] != NumeroCuenta[i - 1]) CantidadAlumnos++;
	}

	printf("%i\n", CantidadAlumnos);

	for (int i = 0; i < NumeroDeCalificaciones; i++) {

		if (NumeroCuenta[i] != NumeroCuenta[i - 1]) {
			printf("%i %f\n", NumeroCuenta[i], calificaciones[i]);

		}
	}

	return 0;
}





