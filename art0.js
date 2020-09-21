class Art0 {
    static getRando(base, range) {
      return base + Math.floor(Math.random() * range + 1);
    }

    static getPoint(side, width, height) {
      switch (side) {
        case 0:
          return [
            0,
            Art0.getRando(0, height),
          ];
        case 1:
          return [
            Art0.getRando(0, width),
            0,
          ];
        case 2:
          return [
            width,
            Art0.getRando(0, height),
          ];
        default: return undefined;
      }
    }
  
  
    paint(ctx, { width, height }, props) { // eslint-disable-line
      
  
      ctx.fillStyle = 'rgb(189, 196, 224)';
      ctx.fillRect(0, 0, width, height);
  
      const ctr = [
        width * Math.random(),
        height + 109,
      ];
  
      for (let i = 0; i < 150; i += 1) {
        const endSide = i % 3;
        ctx.beginPath();
        ctx.moveTo(...ctr);
        ctx.lineTo(...Art0.getPoint(endSide, width, height));
        ctx.lineWidth = Art0.getRando(0, 85);
        ctx.lineCap = 'round';
        ctx.strokeStyle = `rgba(${Art0.getRando(155, 100)}, ${Art0.getRando(120, 100)}, ${Art0.getRando(30, 120)}, .07)`;
        ctx.stroke();
      }
    }
  }
  registerPaint('art0', Art0);