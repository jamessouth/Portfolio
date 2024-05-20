/** @type {import('tailwindcss').Config} */
export default {
  content: ['./index.html', './src/**/*.res.mjs'],
  theme: {
    extend: {
      backgroundImage: {
        clean: 'url(/clean.jpg)',
        pe: "url('https://projecteuler.net/profile/jamessouth.png')",
        cw: "url('https://www.codewars.com/users/jamessouth/badges/micro')",
        'cw-lg':
          "url('https://www.codewars.com/users/jamessouth/badges/large')",
      },
      //   backgroundImage: {
      //     "entry_mob_wide":"url(/entryMobWide.jpg)",
      //     "entry_mob_tall":"url(/entryMobTall.jpg)"
      //   }
      colors: {
        'dark-blue': '#405d82',
        'eerie-black': '#161616',
        'img-bg': '#e2e2e2',
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
        portrait: {
          raw: '(orientation: portrait)',
        },
        landscape500: {
          raw: '(orientation: landscape) and (min-height: 500px)',
        },
        wdk1: '440px',
      },
    },
  },
  corePlugins: {
    animation: false,
  },
};
