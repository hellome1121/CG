#include <windows.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -6.0f); // Move the cuboid back along the z-axis
    glRotatef(45, 1.0f, 1.0f, 1.0f); // Rotate the cuboid

    // Front face
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom left
    glVertex3f(1.0f, -1.0f, 1.0f); // Bottom right
    glVertex3f(1.0f, 1.0f, 1.0f); // Top right
    glVertex3f(-1.0f, 1.0f, 1.0f); // Top left
    glEnd();

    // Back face
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom left
    glVertex3f(1.0f, -1.0f, -1.0f); // Bottom right
    glVertex3f(1.0f, 1.0f, -1.0f); // Top right
    glVertex3f(-1.0f, 1.0f, -1.0f); // Top left
    glEnd();

    // Top face
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex3f(-1.0f, 1.0f, -1.0f); // Front bottom left
    glVertex3f(1.0f, 1.0f, -1.0f); // Front bottom right
    glVertex3f(1.0f, 1.0f, 1.0f); // Front top right
    glVertex3f(-1.0f, 1.0f, 1.0f); // Front top left
    glEnd();

    // Bottom face
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glVertex3f(-1.0f, -1.0f, -1.0f); // Front bottom left
    glVertex3f(1.0f, -1.0f, -1.0f); // Front bottom right
    glVertex3f(1.0f, -1.0f, 1.0f); // Front top right
    glVertex3f(-1.0f, -1.0f, 1.0f); // Front top left
    glEnd();

    // Right face
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta color
    glVertex3f(1.0f, -1.0f, -1.0f); // Bottom back
    glVertex3f(1.0f, -1.0f, 1.0f); // Bottom front
    glVertex3f(1.0f, 1.0f, 1.0f); // Top front
    glVertex3f(1.0f, 1.0f, -1.0f); // Top back
    glEnd();

    // Left face
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan color
    glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom back
    glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom front
    glVertex3f(-1.0f, 1.0f, 1.0f); // Top front
    glVertex3f(-1.0f, 1.0f, -1.0f); // Top back
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Cuboid");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
