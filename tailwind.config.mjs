/** @type {import('tailwindcss').Config} */
export default {
  content: ['./index.html', './src/**/*.res.mjs'],
  theme: {
    extend: {
      backgroundImage: {
        about: "url('/about.jpg')",
        clean: "url('/clean.jpg')",
        port: "url('/port.jpg')",
        pe: "url('https://projecteuler.net/profile/jamessouth.png')",
        cw: "url('https://www.codewars.com/users/jamessouth/badges/micro')",
        'cw-lg':
          "url('https://www.codewars.com/users/jamessouth/badges/large')",
      },
      colors: {
        'dark-blue': '#405d82',
      },
      fontFamily: {
        cinz: 'Cinzel, serif',
        corm: '"Cormorant SC", serif',
        forum: 'Forum, cursive',
        gara: 'EB Garamond, serif',
      },
      height: {
        'half-screen': '50vh',
      },
      maxWidth: {
        artw: '16rem',
        cont: '2000px',
      },
      spacing: {
        iconw: '39px',
        iconh: '37px',
        'cw-lg': '25rem',
      },
      screens: {
        wdk1: '440px',
      },
    },
  },
  corePlugins: {
    animation: false,
  },
};
