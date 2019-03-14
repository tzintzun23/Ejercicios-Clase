//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//

//Nombre: Hernández Tzintzun Daniel
//Práctica: 5
//Versión VS: 2017
//Instrucciones: Brazo con movimiento. Se realizó un brazo con distintos puntos de articulación,
// solo dos para cada dedo (excepto el pulgar, solo cuenta con un movimiento) para manejar las articulaciones
// se usan las siguientes teclas:
//
// Articulación Codo => 'r' y 'R'
// Articulación Muñeca => 't' y 'T'
// Articulación Dedo Pulgar => 'y' y 'Y'
// Articulación Dedo Índice => 'u' y 'U'
// Articulación Dedo Índice2 => 'j' y 'J'
// Articulación Dedo Medio => 'i' e 'I'
// Articulación Dedo Medio2 => 'k' y 'K'
// Articulación Dedod Anular => 'o' y 'O'
// Articulación Dedod Anular2 => 'l' y 'L'
// Articulación Dedo Meñique => 'p' y 'P'
// Articulación Dedo Meñique2 => 'm' y 'M'

#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;

float angCodo = 0.0f;
float angMuneca = 0.0f;
float angPulgar = 0.0f;
float angIndice = 0.0f;
float angIndice2 = 0.0f;
float angMedio = 0.0f;
float angMedio2 = 0.0f;
float angAnular = 0.0f;
float angAnular2 = 0.0f;
float angMenique = 0.0f;
float angMenique2 = 0.0f;

GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);

	//Poner Código Aquí.

	//Brazo
	glPushMatrix();

		//Hombro
		glPushMatrix();
			glColor3f(1, 1, 0);
			prisma();
		glPopMatrix();

		glTranslatef(1.5, 0, 0);

		//Bicep
		glPushMatrix();
			glColor3f(1, 0, 0);
			glScalef(2, 1, 1);
			prisma();
		glPopMatrix();

		glTranslatef(1, 0, 0);
			glRotatef(angCodo, 0, 1, 0);	//Articulación codo
		glTranslatef(1, 0, 0);

		//Antebrazo
		glPushMatrix();
			glColor3f(0, 0, 1);
			glScalef(2, 1, 1);
			prisma();
		glPopMatrix();

		glTranslatef(1, 0, 0);
			glRotatef(angMuneca, 0, 1, 0);	//Articulación muñeca
		glTranslatef(0.5, 0, 0);

		//Palma
		glPushMatrix();
			glColor3f(0.8, 0.4, 0.2);
			glScalef(1, 1, 0.5);
			prisma();
		glPopMatrix();

		//Pulgar
		glPushMatrix();
		glTranslatef(-0.4, 0.6, 0);
			//Falange1
			glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glScalef(0.2, 0.2, 0.5);
				prisma();
			glPopMatrix();

			glTranslatef(0, 0.1, 0);
				glRotatef(angPulgar, 1, 0, 0);	//Articulación pulgar
			glTranslatef(0, 0.1, 0);

			//Falange2
			glPushMatrix();
				glColor3f(0.4, 0.2, 0.3);
				glScalef(0.2, 0.2, 0.5);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//Índice
		glPushMatrix();
		glTranslatef(0.65, 0.45, 0);
			//Falange 1
			glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glScalef(0.3, 0.1, 0.5);
				prisma();
			glPopMatrix();

			glTranslatef(0.15, 0.0, 0.0);
				glRotatef(angIndice, 0, 1, 0);	//Articulación indice 1
			glTranslatef(0.15, 0.0, 0.0);

			//Falange2
			glPushMatrix();
				glColor3f(0.4, 0.2, 0.3);
				glScalef(0.3, 0.1, 0.5);
				prisma();
			glPopMatrix();

			//glTranslatef(0.3, 0.0, 0.0);

			glTranslatef(0.15, 0.0, 0.0);
				glRotatef(angIndice2, 0, 1, 0);	//Articulación indice 2
			glTranslatef(0.15, 0.0, 0.0);


			//Falange3
			glPushMatrix();
				glColor3f(1, 0, 0);
				glScalef(0.3, 0.1, 0.5);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//Medio
		glPushMatrix();
		glTranslatef(0.70, 0.15, 0);
			//Falange 1
			glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glScalef(0.4, 0.1, 0.5);
				prisma();
			glPopMatrix();

			glTranslatef(0.20, 0.0, 0.0);
				glRotatef(angMedio, 0, 1, 0);	//Articulación medio
			glTranslatef(0.20, 0.0, 0.0);

			//Falange2
			glPushMatrix();
				glColor3f(0.4, 0.2, 0.3);
				glScalef(0.4, 0.1, 0.5);
				prisma();
			glPopMatrix();

			//glTranslatef(0.4, 0.0, 0.0);

			glTranslatef(0.20, 0.0, 0.0);
				glRotatef(angMedio2, 0, 1, 0);	//Articulación medio 2
			glTranslatef(0.20, 0.0, 0.0);

			//Falange3
			glPushMatrix();
				glColor3f(1, 0, 0);
				glScalef(0.4, 0.1, 0.5);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//Anular
		glPushMatrix();
		glTranslatef(0.65, -0.15, 0);
			//Falange 1
			glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glScalef(0.3, 0.1, 0.5);
				prisma();
			glPopMatrix();

			glTranslatef(0.15, 0.0, 0.0);
				glRotatef(angAnular, 0, 1, 0);	//Articulación anular
			glTranslatef(0.15, 0.0, 0.0);

			//Falange2
			glPushMatrix();
				glColor3f(0.4, 0.2, 0.3);
				glScalef(0.3, 0.1, 0.5);
				prisma();
			glPopMatrix();

			//glTranslatef(0.3, 0.0, 0.0);

			glTranslatef(0.15, 0.0, 0.0);
				glRotatef(angAnular2, 0, 1, 0);	//Articulación anular 2
			glTranslatef(0.15, 0.0, 0.0);

			//Falange3
			glPushMatrix();
				glColor3f(1, 0, 0);
				glScalef(0.3, 0.1, 0.5);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//Meñique
		glPushMatrix();
		glTranslatef(0.60, -0.45, 0);
			//Falange 1
			glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glScalef(0.2, 0.1, 0.5);
				prisma();
			glPopMatrix();

			glTranslatef(0.10, 0.0, 0.0);
				glRotatef(angMenique, 0, 1, 0);	//Articulación meñique
			glTranslatef(0.10, 0.0, 0.0);

			//Falange2
			glPushMatrix();
				glColor3f(0.4, 0.2, 0.3);
				glScalef(0.2, 0.1, 0.5);
				prisma();
			glPopMatrix();

			//glTranslatef(0.2, 0.0, 0.0);

			glTranslatef(0.10, 0.0, 0.0);
				glRotatef(angMenique2, 0, 1, 0);	//Articulación meñique 2
			glTranslatef(0.10, 0.0, 0.0);

			//Falange3
			glPushMatrix();
				glColor3f(1, 0, 0);
				glScalef(0.2, 0.1, 0.5);
				prisma();
			glPopMatrix();
		glPopMatrix();


	glPopMatrix();
  											
	glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;


		case 'r':
			if(angCodo<=130)
			angCodo += 0.8f;
			break;
		case 'R':
			if (angCodo >= 0)
			angCodo -= 0.8f;
			break;

		case 't':
			if (angMuneca <= 85)
				angMuneca += 0.8f;
			break;
		case 'T':
			if (angMuneca >= -30)
				angMuneca -= 0.8f;
			break;

		case 'y':
			if (angPulgar >= -90)
				angPulgar -= 0.8f;
			break;
		case 'Y':
			if (angPulgar <= 0)
				angPulgar += 0.8f;
			break;

		case 'u':
			if (angIndice <= 90)
				angIndice += 0.8f;
			break;
		case 'U':
			if (angIndice >= 0)
				angIndice -= 0.8f;
			break;

		case 'j':
			if (angIndice2 <= 90)
				angIndice2 += 0.8f;
			break;
		case 'J':
			if (angIndice2 >= 0)
				angIndice2 -= 0.8f;
			break;

		case 'i':
			if (angMedio <= 90)
				angMedio += 0.8f;
			break;
		case 'I':
			if (angMedio >= 0)
				angMedio -= 0.8f;
			break;

		case 'k':
			if (angMedio2 <= 90)
				angMedio2 += 0.8f;
			break;
		case 'K':
			if (angMedio2 >= 0)
				angMedio2 -= 0.8f;
			break;

		case 'o':
			if (angAnular <= 90)
				angAnular += 0.8f;
			break;
		case 'O':
			if (angAnular >= 0)
				angAnular -= 0.8f;
			break;

		case 'l':
			if (angAnular2 <= 90)
				angAnular2 += 0.8f;
			break;
		case 'L':
			if (angAnular2 >= 0)
				angAnular2 -= 0.8f;
			break;

		case 'p':
			if (angMenique <= 90)
				angMenique += 0.8f;
			break;
		case 'P':
			if (angMenique >= 0)
				angMenique -= 0.8f;
			break;

		case 'm':
			if (angMenique2 <= 90)
				angMenique2 += 0.8f;
			break;
		case 'M':
			if (angMenique2 >= 0)
				angMenique2 -= 0.8f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}
