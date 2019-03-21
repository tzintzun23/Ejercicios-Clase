//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//

//Alumno: Hernández Tzintzun Daniel
//Práctica: 6
//Versión VS: 2017
//Instrucciones: En este ejercicio, se realizó una representación
// del sistema solar, el cual solo incluye al sol y a los planetas
// de Mercurio, Venus, Tierra, Jupiter y Saturno. Estos rotan y se
// trasladan a distintas velocidades. También agregué la función de
// las teclas up y down, para poder visualizar de mejor manera los
// movimientos de cada planeta.


#include "Main.h"

// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

//Variables used to create movement

int sol=0;

int traslacionMercurio = 0;
int rotacionMercurio = 0;

int traslacionVenus = 0;
int rotacionVenus = 0;

int traslacionTierra = 0;
int rotacionTierra = 0;

int traslacionLuna = 0;

int traslacionJupiter = 0;
int rotacionJupiter = 0;

int traslacionSaturno = 0;
int rotacionSaturno = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

float angleX = 0.0f;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	glRotatef(angleX, 1.0, 0.0, 0.0);
	
	//Sol
	glPushMatrix();
		glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
		glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
		glutSolidSphere(1.9,12,12);  //Draw Sun (radio,H,V);
	glPopMatrix();

	//Mercurio
	glColor3f(0.93, 0.62, 0.32);
	glPushMatrix();
		glRotatef(traslacionMercurio, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(3.0, 0.0, 0.0);
			glRotatef(rotacionMercurio, 0.0, 1.0, 0.0);
			glutSolidSphere(0.3, 12, 12);
		glPopMatrix();
	glPopMatrix();

	//Venus
	glColor3f(0.99, 0.45, 0.34);
	glPushMatrix();
		glRotatef(traslacionVenus, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(4.5, 0.0, 0.0);
			glRotatef(rotacionMercurio, 0.0, 1.0, 0.0);
			glutSolidSphere(0.4, 12, 12);
		glPopMatrix();
	glPopMatrix();

	//Tierra
	glColor3f(0.25, 0.68, 0.91);
	glPushMatrix();
		glRotatef(traslacionTierra, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(6.0, 0.0, 0.0);
			glRotatef(rotacionTierra, 0.0, 1.0, 0.0);
			glutSolidSphere(0.5, 12, 12);
			//Luna
			glColor3f(0.71, 0.72, 0.72);
			glPushMatrix();
				glTranslatef(1.0, 0.0, 0.0);
				glRotatef(traslacionLuna, 0.0, 1.0, 0.0);
				glutSolidSphere(0.2, 12, 12);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	//Jupiter
	glColor3f(1, 0.85, 0.63);
	glPushMatrix();
		glRotatef(traslacionJupiter, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(8.5, 0.0, 0.0);
			glRotatef(rotacionJupiter, 0.0, 1.0, 0.0);
			glutSolidSphere(0.7, 12, 12);
			//Luna 1
			glColor3f(0.71, 0.72, 0.72);
			glPushMatrix();
				glTranslatef(1.0, 0.0, 0.0);
				glRotatef(traslacionLuna, 0.0, 1.0, 0.0);
				glutSolidSphere(0.2, 12, 12);
			//glPopMatrix();
			//Luna 2
			glColor3f(0.71, 0.72, 0.72);
			//glPushMatrix();
				glTranslatef(0.0, 1.0, 0.0);
				glRotatef(traslacionLuna, 0.0, 1.0, 0.0);
				glutSolidSphere(0.2, 12, 12);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	//Saturno
	glColor3f(1, 0.9, 0.76);
	glPushMatrix();
		glRotatef(traslacionSaturno, 0.0, 1.0, 0.0);
		glPushMatrix();
			glTranslatef(14.0, 0.0, 0.0);
			glRotatef(rotacionSaturno, 0.0, 1.0, 0.0);
			glutSolidSphere(0.6, 12, 12);
			//Anillo
			glRotatef(90, 1, 0, 0);
			glScalef(0.9, 0.9, 0.1);
			glColor3f(0.71, 0.72, 0.72);
			glutSolidTorus(1.0, 2.5, 20, 20);
		glPopMatrix();
	glPopMatrix();

	glutSwapBuffers ( );
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;

		rotacionMercurio = (rotacionMercurio - 4) % 360;
		traslacionMercurio = (traslacionMercurio - 3) % 360;

		rotacionVenus = (rotacionVenus - 2) % 360;
		traslacionVenus = (traslacionVenus - 4) % 360;

		rotacionTierra = (rotacionTierra - 1) % 360;
		traslacionTierra = (traslacionTierra - 2) % 360;
		traslacionLuna = (traslacionLuna - 6) % 360;

		rotacionJupiter = (rotacionJupiter - 1) % 360;
		traslacionJupiter = (traslacionJupiter - 3) % 360;

		rotacionSaturno = (rotacionSaturno - 1) % 360;
		traslacionSaturno = (traslacionSaturno - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}
	glutPostRedisplay();
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
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}