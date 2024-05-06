void controls(void)
{
    int delta[3] = {0,0,0}; // Speed
	int i; //target object
	
	if (!jo_is_pad1_available())
		return ;
	
	//Movement
	
	if (jo_is_pad1_key_pressed(JO_KEY_C)){
	delta[1] = 32;}
    if (jo_is_pad1_key_pressed(JO_KEY_L))
	{delta[0] = -32;}
	if (jo_is_pad1_key_pressed(JO_KEY_R))
	{delta[0] = 32;}
    if (jo_is_pad1_key_pressed(JO_KEY_DOWN))
	{delta[2] = -32;}
	if (jo_is_pad1_key_pressed(JO_KEY_UP))
	{delta[2] = 32;}
	if (jo_is_pad1_key_pressed(JO_KEY_LEFT))
	{cam_angle[1] -= 3;}
	if (jo_is_pad1_key_pressed(JO_KEY_RIGHT))
	{cam_angle[1] += 3;}
    if (jo_is_pad1_key_pressed(JO_KEY_START))
    

	//Targeting
	
	i=0;
	if (jo_is_pad1_key_pressed(JO_KEY_Z)){
	if 	(cam_angle[1] < jo_atan2f(casks[i].x - cam_pos[0], casks[i].z - cam_pos[2]))
	{cam_angle[1] += 3;}
if 	(cam_angle[1] > jo_atan2f(casks[i].x - cam_pos[0], casks[i].z - cam_pos[2]))
	{cam_angle[1] -= 3;}
 if (jo_is_pad1_key_pressed(JO_KEY_LEFT))
		delta[0] = -32;
	if (jo_is_pad1_key_pressed(JO_KEY_RIGHT))
		delta[0] = 32;	
 if (jo_is_pad1_key_pressed(JO_KEY_X))
		i--;
	if (jo_is_pad1_key_pressed(JO_KEY_Y))
		i++;	
}


		   //  Bound Camera Angle
	if (cam_angle[1] > 180)
        cam_angle[1] -= 360;
    else if (cam_angle[1] <= -180)
	cam_angle[1] += 360;


	//Gravity
	delta[1] += 30;
	
   //  Rate of change of Camera Position multiplied by 16 for more precision
    dcpos[0] += (delta[0]*jo_cos(cam_angle[1]) + delta[2]*jo_sin(cam_angle[1]))>>15;
    dcpos[1] += delta[1];
    dcpos[2] += (delta[2]*jo_cos(cam_angle[1]) - delta[0]*jo_sin(cam_angle[1]))>>15;
	
	// Change cam position divide by 16 with bitshift
	cam_pos[0] = dcpos[0]>>4;
    cam_pos[1] = dcpos[1]>>4;
    cam_pos[2] = dcpos[2]>>4;
	

    //  Fix Camera Target/Orientation
    cam_tar[0] = (cam_pos[0]) + (100*jo_sin(cam_angle[1])>>15);
    cam_tar[1] = cam_pos[1];
    cam_tar[2] = (cam_pos[2]) + (100*jo_cos(cam_angle[1])>>15);
}

