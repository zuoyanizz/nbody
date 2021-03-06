#ifndef WGT_NBODY_PLAYER_CONTROL_H
#define WGT_NBODY_PLAYER_CONTROL_H

#include <QWidget>
#include <QPropertyAnimation>

class nbody_data_stream_reader;
class QLabel;
class QSlider;
class QSpinBox;
class QDoubleSpinBox;

class wgt_nbody_player_control : public QWidget
{
	Q_OBJECT
	QSlider*			m_timeline;
	QSlider*			m_stereo_base;
	QSpinBox*			m_stars_intensity;
	QDoubleSpinBox*		m_stars_size;
	QDoubleSpinBox*		m_scale;
	QLabel*				m_frame_number;
	QPropertyAnimation*	m_animation;
	QAction*			m_act_start;
	QAction*			m_act_pause;
	QAction*			m_act_backward;
	QAction*			m_act_stop;
	QAction*			m_act_forward;
	QAction*			m_act_record;
	QAction*			m_color_from_velosity;
	QAction*			m_show_box;
public:
	wgt_nbody_player_control(QWidget* parent, const nbody_data_stream_reader* stream);
	size_t get_current_frame() const;
	int get_stereo_base() const;
	int get_star_intensity() const;
	double get_star_size() const;
	void set_star_size_range(double, double, double);
	bool get_color_from_velosity() const;
	bool get_show_box() const;
	double get_scale() const;
public slots:
	void on_start();
	void on_pause();
	void on_backward();
	void on_stop();
	void on_forward();
	void on_finished();
	void on_stereo_base_changed();
	void on_frame_number_updated();
	void on_stars_size_range_changed(double, double, double);
signals:
	void frame_number_updated();
	void frame_state_updated();
	void star_intensity_updated();
	void star_size_updated();
	void start_record();
	void color_from_velosity_changed();
	void show_box_changed();
	void scale_changed();
};

#endif // WGT_NBODY_PLAYER_CONTROL_H
