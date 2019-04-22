import pdfkit

for i in range(1,40):
	url = 'http://embedded.cse.iitd.ernet.in/~sbansal/os/lec/l'+ str(i) + '.html'
	pdfname = 'Lecture_'+str(i)+'sbansal.pdf'
	pdfkit.from_url(url,pdfname)