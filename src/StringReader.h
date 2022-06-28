#ifndef StringReader_h
#define StringReader_h

#include <Stream.h>

typedef void (*stringReaderCallback)(char* str);

template<uint16_t MAX_SIZE = 50>
class StringReader 
{
	private:
	
	char m_buffer[MAX_SIZE];
	uint16_t m_pos;
	Stream* m_stream;
	stringReaderCallback m_callback;
	char m_terminator;
	
	public:
	
	StringReader(Stream* stream, char terminator, stringReaderCallback callback)
	{
		m_terminator = terminator;
		m_stream = stream;
		m_callback = callback;
		
		m_pos = 0;
		memset(m_buffer, 0, MAX_SIZE);

	}

	void update()
	{
		if(m_stream -> available()>0)
		{
			char c = m_stream -> read();
			if(c == m_terminator)
			{
				m_callback(m_buffer);
				m_pos = 0;
				memset(m_buffer, 0, MAX_SIZE);
			}
			else
			{
				if( m_pos < MAX_SIZE-1)
				{
					m_buffer[m_pos] = c;
					m_pos++;
				}
			}
		}
	}
};


#endif
