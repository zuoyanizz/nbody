#include "nbody_solvers.h"

template<class Solver>
static nbody_solver* create_butcher_solver(const QVariantMap& param)
{
	nbody_solver_rk_butcher*	solver = new Solver();

	solver->set_error_threshold(param.value("error_threshold", 1e-4).toDouble());
	solver->set_max_recursion(param.value("max_recursion", 8).toUInt());
	solver->set_refine_steps_count(param.value("refine_steps_count", 1).toUInt());
	solver->set_substep_subdivisions(param.value("substep_subdivisions", 8).toUInt());

	return solver;
}

nbody_solver* nbody_create_solver(const QVariantMap& param)
{
	const QString	type(param.value("solver").toString());
	nbody_solver*	solver = NULL;
	if(type == "adams")
	{
		solver = new nbody_solver_adams(param.value("rank", 1).toInt());
	}
	else if(type == "euler")
	{
		solver = new nbody_solver_euler();
	}
	else if(type == "rk4")
	{
		solver = new nbody_solver_rk4();
	}
	else if(type == "rkck")
	{
		solver = create_butcher_solver<nbody_solver_rkck>(param);
	}
	else if(type == "rkdp")
	{
		solver = create_butcher_solver<nbody_solver_rkdp>(param);
	}
	else if(type == "rkf")
	{
		solver = create_butcher_solver<nbody_solver_rkf>(param);
	}
	else if(type == "rkgl")
	{
		solver = create_butcher_solver<nbody_solver_rkgl>(param);
	}
	else if(type == "rklc")
	{
		solver = create_butcher_solver<nbody_solver_rklc>(param);
	}
	else if(type == "trapeze")
	{
		nbody_solver_trapeze* trapeze =  new nbody_solver_trapeze();
		trapeze->set_refine_steps_count(param.value("refine_steps_count", 1).toUInt());
		solver = trapeze;
	}
	else
	{
		return NULL;
	}

	nbcoord_t min_step = param.value("min_step", 1e-9).toDouble();
	nbcoord_t max_step = param.value("max_step", 1e-2).toDouble();

	solver->set_time_step(min_step, max_step);

	return solver;
}