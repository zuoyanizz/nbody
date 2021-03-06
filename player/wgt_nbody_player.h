#ifndef WGT_NBODY_PLAYER_H
#define WGT_NBODY_PLAYER_H

#include <QWidget>
#include "nbtype.h"

class nbody_solver;
class nbody_data;
class nbody_data_stream_reader;
class wgt_nbody_view;
class wgt_nbody_player_control;

class wgt_nbody_player : public QWidget
{
	Q_OBJECT
	wgt_nbody_view*				m_view;
	wgt_nbody_player_control*	m_control;
	nbody_data_stream_reader*	m_stream;
	nbody_data*					m_data;
public:
	explicit wgt_nbody_player(nbody_data_stream_reader* stream,
							  const QString& check_list);
	~wgt_nbody_player();
public slots:
	void on_update_data();
	void on_update_view();
	void on_start_record();
};

#endif // WGT_NBODY_PLAYER_H
