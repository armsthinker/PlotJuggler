#ifndef CUSTOMTRACKER_H
#define CUSTOMTRACKER_H


#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_marker.h>
#include <QEvent>

class QwtPlotCurve;


class CurveTracker: public QObject
{
    Q_OBJECT
public:
    explicit CurveTracker(QwtPlot * );

    QPointF actualPosition() const;

    typedef enum {
        LINE_ONLY,
        VALUE,
        VALUE_NAME
    }Parameter;

public slots:

    void setPosition(const QPointF & pos);

    void setParameter(Parameter par);

    void setEnabled(bool enable);

private:
    QLineF  curveLineAt( const QwtPlotCurve *, double x ) const;

    QPointF transform( QPoint);
    QPoint  invTransform( QPointF);

    QPointF _prev_trackerpoint;
    std::vector<QwtPlotMarker*> _marker;
    QwtPlotMarker* _line_marker;
    QwtPlotMarker* _text_marker;
    QwtPlot* _plot;
    Parameter _param;
    bool _visible;

};

#endif // CUSTOMTRACKER_H
