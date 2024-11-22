struct CubicSpline {
	double t0 , tf;
	PrVector a0 , a1 , a2 , a3;
};
CubicSpline spline;

// Compute total trajectory length
double computeTf ( GlobalVariables & gv)
{
	double max_duration = 0.0;
	
	for(int i=0; i<gv.dof; i++){
	
		double delta_q = abs(gv.qd[i] - gv.q[i]);
		//velocity constraint -> assuma max_v at tf/2
		double time_limit_v = 3 * delta_q / (2 * gv.dqmax[i]);
	
		//acceleration constraint -> assum max_acc at t=0
		double time_limit_acc = sqrt(6 * delta_q / gv.ddqmax[i]);
		
		double cur_max = max(time_limit_v, time_limit_acc);
		
		max_duration = max(cur_max, max_duration);
	}
	
	return max_duration;
}



void initNjtrackControl(GlobalVariables& gv) 

{

  //calc gv.dq[0]
  spline.t0 = gv.curTime;
  spline.tf = computeTf(gv);
  
  int dof = 3;
  spline.a0 = PrVector(dof);
  spline.a1 = PrVector(dof);
  spline.a2 = PrVector(dof);
  spline.a3 = PrVector(dof);
  int entries[3] = {1, 2, 4};
  
  
  for(int i=0; i<dof; i++){
  	spline.a0[i] = gv.q[entries[i]];
  	spline.a2[i] = (3 / pow(spline.tf, 2.0)) * (gv.qd[entries[i]] - gv.q[entries[i]]);
  	spline.a3[i] = (2 / pow(spline.tf, 3.0)) * (gv.qd[entries[i]] - gv.q[entries[i]]);
  }
  /*a0 = gv.q[0]
  a2 = (3 / pow(spline.tf, 2.0)) * (gv.qd[0] - gv.q[0])
  a3 = (2 / pow(spline.tf, 3.0)) * (gv.qd[0] - gv.q[0])*/
  

}