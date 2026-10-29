        });
    }
});

export { app };
export default app;

app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});
