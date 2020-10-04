module.exports = {
    purge: [],
    theme: {
        extend: {
            backgroundImage: {
                'pe': "url('https://projecteuler.net/profile/jamessouth.png')",
                'cw': "url('https://www.codewars.com/users/jamessouth/badges/micro')",
                'cw-lg': "url('https://www.codewars.com/users/jamessouth/badges/large')",
            },
            colors: {
                'dark-blue': '#405d82',
                'eerie-black': '#161616',
                'img-bg': '#e2e2e2',
            },
            fontFamily: {
                'cinz': 'Cinzel, serif',
                'corm': '"Cormorant SC", serif',
                'forum': 'Forum, cursive',
                'gara': 'EB Garamond, serif',
                'rob': 'Roboto Mono, monospace',
            },
            fontSize: {
                // 'hdr': '1.3rem',
                // 'first-letter': '5rem',
                // 'first-letter-big': '7rem',
            },
            height: {
                'half-screen': '50vh',
            },
            maxWidth: {
                'artw': '16rem',
                'cont': '2000px',
            },
            objectPosition: {
                'port': '0px',
                'art': '-39px',
                'cont': '-78px',
            },
            spacing: {
                // 'first-letter': '2.65rem',
                'iconw': '39px',
                'iconh': '37px',
                // 'cardw': '20rem',
                'cw-lg': '25rem',
            },
            screens: {
                'portrait': {
                    'raw': '(orientation: portrait)',
                },
                'landscape500': {
                    'raw': '(orientation: landscape) and (min-height: 500px)',
                },
                'wdk1': '440px',
            },
        },
    },
    variants: {},
    plugins: [],
}