
function Q2Plots(iterations)
    syms x y
    F = x * ( 1+ 1.3 * (1-x)) - 0.5 *x*y;
    G = 0.3*y + 1.6 * x*y;
    phase_p_fig = figure('Name','Phase plane plot');
    prevx = 1.0;
    prevy = 1.0;
    an = animatedline(prevx,prevy);
    % plot(prevx,prevy);
    hold on;
    for i=2:iterations
        nextx = double(subs(F, [ x ,y],[prevx,prevy]));
        nexty = double(subs(G, [ x ,y],[prevx,prevy]));
    %     plot(nextx,nexty);
        addpoints(an,nextx,nexty);
        prevx = nextx;
        prevy = nexty;
    end
    saveas(phase_p_fig, 'Phase_plane.png');
    timeseries_fig = figure('Name','Time Series Plot');
    prevx = 1;
    prevy = 1;
    an1 = animatedline(1,prevx);
    an2 = animatedline(1,prevy);
    hold on;
    for i=2:iterations
        nextx = double(subs(F, [ x ,y],[prevx,prevy]));
        nexty = double(subs(G, [ x ,y],[prevx,prevy]));
    %     plot(nextx,nexty);
        addpoints(an1,i,nextx);
        addpoints(an2,i,nexty);
        prevx = nextx;
        prevy = nexty;
    end
    title(['p\_t+1=',"p\_t*(1+1.3*(1-p\_t))- .5*p\_t*q\_t",'  q\_t+1=',".3*q\_t + 1.6*p\_t*q\_t"]);
    saveas(timeseries_fig, 'Time_Series.png');

    prevx = 1;
    prevy = 1;

    p_steadystate_fig = figure('Name','Steady state plot of P');
    hAxes(1) = gca;
    an1 = animatedline(hAxes(1),1,prevx);

    q_steadystate_fig = figure('Name','Steady state pllot of Q');
    hAxes(1) = gca;
    an2 = animatedline(hAxes(1),1,prevy);
    hold on;

    for i=2:iterations
        nextx = double(subs(F, [ x ,y],[prevx,prevy]));
        nexty = double(subs(G, [ x ,y],[prevx,prevy]));
    %     plot(nextx,nexty);
        addpoints(an1,i,nextx);
        addpoints(an2,i,nexty);
        prevx = nextx;
        prevy = nexty;
    end
    saveas(q_steadystate_fig, 'Q_Time_series.png');
    saveas(p_steadystate_fig, 'P_Time_series.png');
end