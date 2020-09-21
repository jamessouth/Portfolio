class Art0 {
    
  
    static getDistAlongSide(max) {
      return Math.floor(Math.random() * (max + 1));
    }
  
    static getWidth() {
      return Math.floor(Math.random() * 85) + 1;
    }
  
    static getPoint(side, width, height) {
      switch (side) {
        case 0:
          return [
            0,
            Art0.getDistAlongSide(height),
          ];
        case 1:
          return [
            Art0.getDistAlongSide(width),
            0,
          ];
        case 2:
          return [
            width,
            Art0.getDistAlongSide(height),
          ];
        default: return undefined;
      }
    }
  
    static getColor(base, range) {
      return base + Math.floor(Math.random() * range + 1);
    }
  
    paint(ctx, { width, height }, props) { // eslint-disable-line
      
  
      ctx.fillStyle = 'rgb(189, 196, 224)';
      ctx.fillRect(0, 0, width, height);
  
      const ctr = [
        width * Math.random(),
        height + 109,
      ];
  
      for (let i = 0; i < 200; i += 1) {
        const endSide = i % 3;
        ctx.beginPath();
        ctx.moveTo(...ctr);
        ctx.lineTo(...Art0.getPoint(endSide, width, height));
        ctx.lineWidth = Art0.getWidth();
        ctx.lineCap = 'round';
        ctx.strokeStyle = `rgba(${Art0.getColor(155, 100)}, ${Art0.getColor(120, 100)}, ${Art0.getColor(30, 120)}, .07)`;
        ctx.stroke();
      }
    }
  }
  registerPaint('art0', Art0);