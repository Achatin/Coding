program project1;
uses crt;
    var otzk, odpvd: text;
        r, mojaOdpvd, spravnaOdpvd: string;
        kolo: integer;
begin
  assign(otzk,'otazky.txt');
  assign(odpvd,'odpovede.txt');
  reset(otzk);
  reset(odpvd);
  textbackground(9);
  textcolor(Yellow);
  writeln(' __    __     __     __         __     ______     __   __     ______     ______    ');
  writeln('/\ "-./  \   /\ \   /\ \       /\ \   /\  __ \   /\ "-.\ \   /\  __ \   /\  == \   ');
  writeln('\ \ \-./\ \  \ \ \  \ \ \____  \ \ \  \ \ \/\ \  \ \ \-.  \  \ \  __ \  \ \  __<   ');
  writeln(' \ \_\ \ \_\  \ \_\  \ \_____\  \ \_\  \ \_____\  \ \_\\"\_\  \ \_\ \_\  \ \_\ \_\ ');
  writeln('  \/_/  \/_/   \/_/   \/_____/   \/_/   \/_____/   \/_/ \/_/   \/_/\/_/   \/_/ /_/ ');
  writeln('                                                                                   ');
  NormVideo;
  textcolor(LightCyan);
  writeln('_______________________________________');
  writeln('Pre pokracovanie stlacte klavesu ENTER');
  readln;
  clrscr;
  textcolor(Red);
  writeln(' ______   ______     ______     __   __   __     _____     __         ______    ');
  writeln('/\  == \ /\  == \   /\  __ \   /\ \ / /  /\ \   /\  __-.  /\ \       /\  __ \   ');
  writeln('\ \  _-/ \ \  __<   \ \  __ \  \ \ \ /   \ \ \  \ \ \/\ \ \ \ \____  \ \  __ \  ');
  writeln(' \ \_\    \ \_\ \_\  \ \_\ \_\  \ \__|    \ \_\  \ \____-  \ \_____\  \ \_\ \_\ ');
  writeln('  \/_/     \/_/ /_/   \/_/\/_/   \/_/      \/_/   \/____/   \/_____/   \/_/\/_/ ');
  writeln;
  textcolor(White);
  writeln;
  writeln('Cielom hry Milionar je odpovedat na 15 otazok, ktorych obtiaznost postupne rastie.');
  writeln('Ku kazdej otazke mate styri moznosti, z ktorych vzdy prave jedna je spravna.');
  writeln('Ak odpoviete na otazku spravne, tak postupujete na dalsiu, ak nespravne, tak hra sa konci.');
  writeln('Na piatej a desiatej otazke su garantovane hranice.');
  writeln('Ak odpoviete nespravne, klesnete na najblizsiu nizsiu garantovanu hranicu resp. na nulu.');
  textcolor(LightCyan);
  writeln('_______________________________________');
  writeln('Pre zaciatok hry stlacte klavesu ENTER');
  readln;

  kolo := 0;

  repeat
  clrscr;
  textcolor(Blue);
  writeln(' _____ _ _ _                 ');
  writeln('|     |_| |_|___ ___ ___ ___ ');
  writeln('| | | | | | | . |   | . |  _|');
  writeln('|_|_|_|_|_|_|___|_|_|__,|_|  ');
  writeln;
  NormVideo;                  // vráti predvolené grafické nastavenia
  readln(otzk, r);            // vypíše všetken text otázky
  writeln(r);
  readln(otzk, r);
  writeln(r);
  readln(otzk, r);
  writeln(r);
  readln(otzk, r);
  writeln(r);
  readln(odpvd, spravnaOdpvd);     // načíta správnu odpoveď z textového dokumentu s odpoveďami
  readln(mojaOdpvd);               // čaká na napísanie mojej odpovede

  if upcase(mojaOdpvd) = spravnaOdpvd then begin
    kolo := kolo + 1;
    textcolor(Green);
    writeln('SPRAVNE!');
    NormVideo;
    case kolo of
      1: writeln('Na konte mate 100 EUR! Gratulujeme :)');
      2: writeln('Na konte mate 200 EUR! Gratulujeme :)');
      3: writeln('Na konte mate 300 EUR! Gratulujeme :)');
      4: writeln('Na konte mate 500 EUR! Gratulujeme :)');
      5: writeln('Na konte mate 1000 EUR! Dostali ste sa na prvu garantovanu hranicu.');
      6: writeln('Na konte mate 2000 EUR! Gratulujeme :)');
      7: writeln('Na konte mate 4000 EUR! Gratulujeme :)');
      8: writeln('Na konte mate 8000 EUR! Gratulujeme :)');
      9: writeln('Na konte mate 16 000 EUR! Gratulujeme :)');
      10: writeln('Na konte mate 32 000 EUR! Dostali ste sa na druhu garantovanu hranicu.');
      11: writeln('Na konte mate 64 000 EUR! Gratulujeme :)');
      12: writeln('Na konte mate 125 000 EUR! Gratulujeme :)');
      13: writeln('Na konte mate 250 000 EUR! Gratulujeme :)');
      14: writeln('Na konte mate 500 000 EUR! Gratulujeme :)');
      15: writeln('Odpovedali ste spravne aj na poslednu otazku a stavate sa MILIONAROM!');
    end;
    delay(5000); end
    else begin
    write('Bohuzial, odpovedali ste ');
    textcolor(Red);
    write('NESPRAVNE');
    textcolor(White);
    write('. Spravna odpoved je ');
    textcolor(LightBlue);
    writeln(spravnaOdpvd);
    NormVideo;
    write('Hra sa pre vas konci. ');
    if kolo >= 10 then begin textcolor(Yellow); writeln('Avsak domov si odnasate vyhru 32 000 EUR z garantovanej hranice. Gratulujeme :)'); end
       else if kolo >= 5 then begin textcolor(Yellow); writeln('Avsak domov si odnasate vyhru 1000 EUR z garantovanej hranice. Gratulujeme :)'); end
            else writeln('Nevyhrali ste nic.');
    readln;
    halt; end;

  until eof(otzk);

  close(otzk);
  close(odpvd);
  readln;
end.
