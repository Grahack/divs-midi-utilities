#ifndef NOTE_LANE_INCLUDED
#define NOTE_LANE_INCLUDED

class NoteLane;

#include <QPainter>
#include <QPoint>
#include <QRect>
#include "lane.h"
#include "midifile.h"
#include "window.h"

class NoteLane: public Lane
{
	Q_OBJECT

public:
	int velocity = 63;
	int pixels_per_note;
	int scroll_y;

	NoteLane(Window* window);
	void paintBackground(QPainter* painter);
	void paintEvents(QPainter* painter, int selected_events_x_offset, int selected_events_y_offset);
	MidiFileEvent_t getEventFromXY(int x, int y);
	QPoint getPointFromEvent(MidiFileEvent_t midi_event);
	MidiFileEvent_t addEventAtXY(int x, int y);
	void moveEventsByXY(int x_offset, int y_offset);
	void selectEventsInRect(int x, int y, int width, int height);
	void moveCursorToEvent(MidiFileEvent_t midi_event);
	QRect getRectFromEvent(MidiFileEvent_t midi_event, int selected_events_x_offset, int selected_events_y_offset);
	int getYFromNote(int note);
	int getNoteFromY(int y);
};

#endif
