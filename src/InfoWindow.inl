void InfoWindow::OnCreate ()
{
}

void InfoWindow::OnDelete ()
{
}

orxBOOL InfoWindow::OnRender ()
{
    //	orxRENDER_EVENT_OBJECT_PAYLOAD *payload =
//	    reinterpret_cast<orxRENDER_EVEN/T_OBJECT_PAYLOAD *> (_pstEvent->pstPayload);
	// Create an OpenGLRenderer object that uses the current GL viewport as
// the default output surface.

	CEGUI::System::getSingleton().renderGUI();
#if 0
	glViewport(0, 0, 100, 100);
	glMatrixMode(GL_PROJECTION); 
	//gluPerspective(45.0f,(GLfloat)100/(GLfloat)100,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);  
	//glLoadIdentity();
	glShadeModel(GL_SMOOTH);  
		
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   
//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
		
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glTranslatef(-1.5f,0.0f,1.0f);  
	glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_TRIANGLES);                      // Drawing Using Triangles
	glVertex3f( 0.0f, 3.0f, 0.0f);              // Top
	glVertex3f(-3.0f,-3.0f, 0.0f);              // Bottom Left
	glVertex3f( 3.0f,-3.0f, 0.0f);              // Bottom Right
	glEnd();  
	glBegin(GL_QUADS);                  // Start Drawing Quads
        glVertex3f(-1.0f, 1.0f, 0.0f);          // Left And Up 1 Unit (Top Left)
        glVertex3f( 1.0f, 1.0f, 0.0f);          // Right And Up 1 Unit (Top Right)
        glVertex3f( 1.0f,-1.0f, 0.0f);          // Right And Down One Unit (Bottom Right)
        glVertex3f(-1.0f,-1.0f, 0.0f);          // Left And Down One Unit (Bottom Left)
	glEnd();  
#endif
   return false; 
}

void InfoWindow::Update(const orxCLOCK_INFO &_rstInfo)
{
    ScrollObject *selectedObj = OrxCraft::GetInstance ().GetSelectedObject ();
    orxVECTOR position;
    selectedObj->GetPosition (position, true);

    char buffer[255];

    CEGUI::Window *rootWindow = CEGUI::System::getSingleton ().getGUISheet ();
    CEGUI::Window *infoWindow = rootWindow->getChild ("InfoWindow");
    CEGUI::Window *textBox    = infoWindow->getChild ("X");
    sprintf (buffer, "%f", position.fX);
    textBox->setText (buffer);
    textBox = infoWindow->getChild ("Y");
    sprintf (buffer, "%f", position.fY);
    textBox->setText (buffer);
    textBox = infoWindow->getChild ("Z");
    sprintf (buffer, "%f", position.fZ);
    textBox->setText (buffer);

    const orxSTRING name = selectedObj->GetModelName ();
    textBox = infoWindow->getChild ("SectionName");
    textBox->setText (name);
}